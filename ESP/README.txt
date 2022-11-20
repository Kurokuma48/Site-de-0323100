O código Mqtt.ino permite que um ESP envie sinais mqtt (ava) para o broker do hivemq (broker.mqttdashboard.com);
O controle é feito pela node intaladas no software Node-Red running localmente no pc do Pedro Kings;
Em suma essas nodes recebem de um arquivo de texto (CSV?) e traduzem lendo quais esps tem q ascender,
(claro que apenas um está operando), e enviam para os subsequentes microcontroladores os sinais 0, 1 ou 2, onde:

0 (ou qualquer outra coisa) - volta ao funcionamento normal do cruzamento.
	O botão na porta GPIO23 tbm tem acesso a essa mudança de estado, alterando para 0 sempre q apertado,
	a ideia é que a passagem de uma ambulancia seja justamente esse botão
1 - Ennable o funcionamento do semáforo mais a esquerda (portas 14 (green), 13 (red) e 12 (yellow))
	permaneça ligado indefinidamente, até que ou o botão 23 seja apertado ou um sinal 0 mqtt chegue.
	Tbm liga o led interno do esp quando chega 1 ao controlador;
2 - Semelhante a 1, mas para o semáforo mais a direita (portas 25 (green), 27 (red) e 26 (yellow));


O backup das nodes parciais ainda não finalizadas se enontram no arquivo JSON;