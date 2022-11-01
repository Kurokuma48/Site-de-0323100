from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from django.urls import reverse
from django.template import loader
from ctypes import *

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

def addrecord(request):
	if request.method == 'POST':
		form = PedidoDeSocorro(request.POST)
		if form.is_valid():
			a = form.cleaned_data['local']
			b = form.cleaned_data['telefone']
			c = form.cleaned_data['nome']
			d = form.cleaned_data['ocorrencia']
			e = form.cleaned_data['gravidade']
            
			Ocorrencia(local=a, telefone=b, nome=c, ocorrencia=d, gravidade=e).save()
			return HttpResponseRedirect(reverse('Area-de-espera'))
		else:
			return HttpResponseRedirect(reverse('Area-do-paciente'))
	else:
		return HttpResponseRedirect(reverse('Area-do-paciente'))



def paginaProfissional(request): 
	ocorrencias = Ocorrencia.objects.all().order_by('gravidade').values()
	template = loader.get_template('Area-do-Profissional.html')
	context = {
		'ocorrencias' : ocorrencias,
	}
	return HttpResponse(template.render(context, request))

def aceitarPedido(request, id):
	ocorrenciaAtual = Ocorrencia.objects.get(id=id)
#	path0 = trace(c_int(ocorrenciaAtual.values().local))
	ocorrenciaAtual.delete()
	return HttpResponseRedirect(reverse('Area-do-Profissional'))
