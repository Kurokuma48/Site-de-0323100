from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader

def index(request):
#    template = loader.get_template('Menu-inicial.html')
#    return HttpResponse(template.render())
    return render(request, 'Menu-inicial.html', {})

def paciente(request):
    return render(request, 'Area-do-paciente.html', {})