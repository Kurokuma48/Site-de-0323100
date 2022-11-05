from django.db import models

# Create your models here.

class Ocorrencia(models.Model):
	local = models.IntegerField()
	telefone = models.IntegerField()
	nome = models.CharField(max_length=255)
	ocorrencia = models.CharField(max_length=255)
	gravidade = models.IntegerField()
	aceito = models.CharField(max_length=1)
