#from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader

def index(request):
    template = loader.get_template('Menu-inicial.html')
    return HttpResponse(template.render())

def paciente(request):
    template = loader.get_template('Area-do-paciente.html')
    return HttpResponse(template.render())
