from django.urls import path
from . import views

urlpatterns = [
    path('index.html', views.index, name='indexi.html'),
    path('', views.index, name='index.html'),
    path('Area-do-paciente.html', views.paciente, name='Area-do-paciente.html'),
]
