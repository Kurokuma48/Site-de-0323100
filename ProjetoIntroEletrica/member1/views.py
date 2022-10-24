from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from django.template import loader
from .models import Ocorrencia

def index(request):
#    template = loader.get_template('Menu-inicial.html')
#    return HttpResponse(template.render())
    return render(request, 'Menu-inicial.html', {})

def paciente(request):
    template = loader.get_template('Area-do-paciente.html')
    return HttpResponse(template.render({}, request))

def espera(request):
    return render(request, 'Area-de-espera.html')

def addrecord(request):
#    a = request.POST['local']
    b = request.POST['telefone']
    c = request.POST['CPF']
    d = request.POST['nome']
    e = request.POST['ocorrencia']
    f = request.POST['gravidade']
    ocorrencia = Ocorrencia(local="Av Luciano", telefone=b, CPF=c, nome=d, ocorrencia=e, gravidade=f)
    ocorrencia.save()
    return HttpResponseRedirect(reverse('Area-de-espera'))
