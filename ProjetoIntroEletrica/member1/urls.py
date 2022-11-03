from django.urls import path
from . import views

urlpatterns = [
    path('index.html', views.index, name='index.html'),
    path('', views.index, name='index.html'),
    path('Area-do-paciente', views.paciente, name='Area-do-paciente'),
    path('Area-de-espera', views.espera, name='Area-de-espera'),
    path('addrecord/', views.addrecord, name='addrecord'),
#	path('pagina-login', views.paginaLogin, name='pagina-login'),
#	path('tentarLogin/', views.tentarLogin, name='tentarLogin'),
	path('Area-do-Profissional', views.paginaProfissional, name='Area-do-Profissional'),
	path('Aceitar/<int:ID>', views.aceitarPedido, name='Aceitar'),
]
