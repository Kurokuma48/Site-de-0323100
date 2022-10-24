from django.urls import path
from . import views

urlpatterns = [
    path('index.html', views.index, name='index.html'),
    path('', views.index, name='index.html'),
    path('Area-do-paciente', views.paciente, name='Area-do-paciente'),
    path('Area-de-espera', views.espera, name='Area-de-espera'),
    path('addrecord/', views.addrecord, name='addrecord'),
]
