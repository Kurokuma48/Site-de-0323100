from django.db import models

# Create your models here.

class Ocorrencia(models.Model):
    local = models.TextField()
    telefone = models.IntegerField()
    CPF = models.IntegerField(unique=True)
    nome = models.CharField(max_length=255)
    ocorrencia = models.TextField()
