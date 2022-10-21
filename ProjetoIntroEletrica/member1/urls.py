from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('Area-do-paciente.html', views.paciente, name='Area-do-paciente.html'),
]
