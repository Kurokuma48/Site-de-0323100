from django import forms

class PedidoDeSocorro(forms.Form):
    local = forms.IntegerField()
    telefone = forms.IntegerField()
    nome = forms.CharField(max_length=255)
    ocorrencia = forms.CharField(max_length=255)
    gravidade = forms.IntegerField()
