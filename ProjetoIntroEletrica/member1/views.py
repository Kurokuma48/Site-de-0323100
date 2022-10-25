from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from django.urls import reverse
from django.template import loader

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
