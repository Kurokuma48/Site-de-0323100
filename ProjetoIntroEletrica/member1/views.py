from django.shortcuts import render, get_object_or_404
from django.http import HttpResponse, HttpResponseRedirect
from django.urls import reverse
from django.template import loader
import ctypes
from numpy import genfromtxt, flip
import os

from .models import Ocorrencia
from .forms import PedidoDeSocorro

def index(request):
#    template = loader.get_template('Menu-inicial.html')
#    return HttpResponse(template.render())
    return render(request, 'Menu-inicial.html', {})

def paciente(request):
    template = loader.get_template('Area-do-paciente.html')
    return HttpResponse(template.render({}, request))

def espera(request):
    return render(request, 'Area-de-espera.html')

def paginaLogin(request):	
    template = loader.get_template('paginaLogin.html')
    return HttpResponse(template.render({}, request))

##################################################

def addrecord(request):
	if request.method == 'POST':
		form = PedidoDeSocorro(request.POST)
		if form.is_valid():
			a = form.cleaned_data['local']
			b = form.cleaned_data['telefone']
			c = form.cleaned_data['nome']
			d = form.cleaned_data['ocorrencia']
			e = form.cleaned_data['gravidade']


			Ocorrencia(local=a, telefone=b, nome=c, ocorrencia=d, gravidade=e, aceito="N").save()
#			Ocorrencia(local=a, telefone=b, nome=c, ocorrencia=d, gravidade=e).save()
			return HttpResponseRedirect(reverse('Area-de-espera'))
		else:
			return HttpResponseRedirect(reverse('Area-do-paciente'))
	else:
		return HttpResponseRedirect(reverse('Area-do-paciente'))

##################################################

def paginaProfissional(request): 
	ocorrencias = Ocorrencia.objects.all().order_by('gravidade').values()
	template = loader.get_template('Area-do-Profissional.html')
	context = {
		'ocorrencias' : ocorrencias,
	}
	return HttpResponse(template.render(context, request))

##################################################

def aceitarPedido(request, ID):

	ocorrenciaAtual = get_object_or_404(Ocorrencia, id=ID)

	filepath = os.path.join(os.path.dirname(__file__), 'locallibs', 'biblioteca.so')
	lib = ctypes.CDLL(filepath)

#	pegar o caminho do nó 14 (Hospital Universitario) ao local inicial (OBS: caminho de ida = caminho de volta). RETORNA EM ProjetoIntroeletrica/caminho.csv

	lib.tracarRota(ctypes.c_int(ocorrenciaAtual.local))
	
	filepath2 = os.path.join(os.path.dirname(__file__), "..", "caminho.csv")
	vetor = genfromtxt(filepath2, delimiter=',')
	print(vetor)	


# Mandar o sinal para os arduinos (na cuaso não há cruzamentos)

#(o esp tem que voltar ao normal dps que a ambulância passar duas vezes)

# Dar display no caminho

	template = loader.get_template('caminhoDaAmbulancia.html')
	context = {
		'ID' : ID,
		'x' : ocorrenciaAtual,
		'vetor' : vetor,
		'vetorF' : flip(vetor)
	}

#	ocorrenciaAtual.delete()
	ocorrenciaAtual.aceito = 'S'
	ocorrenciaAtual.save()

	return HttpResponse(template.render(context, request))
#	return HttpResponseRedirect(reverse('Area-do-Profissional'))

#########################################

def delete(request, ID):
	get_object_or_404(Ocorrencia, id=ID).delete()
	return HttpResponseRedirect(reverse('Area-do-Profissional'))

def csv(request):
	content = open(os.path.join(os.path.dirname(__file__), "..", "caminho.csv")).read()
	return HttpResponse(content, content_type='text/plain')
