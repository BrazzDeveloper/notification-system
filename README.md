# Notification-System
## Sistema de Notificação para SA-MP










## Descrição basica:
#### Esse sistema permite criar até 3 notificações ao mesmo tempo, podendo escolher em cada notificação: Titulo e Mensagem. Cada notificação fica visivel por um tempo estimado de 8-10 segundos








## Função:
```pawn
native Notificacao(playerid, const titulo[], const mensagem[]);
```

## Retornos:
```pawn 
0: Função falhou e/ou exedeu o limite de 3 notificações ao mesmo tempo
1: Função foi executada com sucesso!
```
## Exemplo de Uso:

```pawn
public OnPlayerSpawn(playerid){
	Notificacao(playerid, "Spawnado", "Voce acaba de spawnar no servidor, parabens. seja bem vindo ao servidor!");
	SetPlayerPos(playerid, 1212.4865,-977.6506,43.4766);
	return 1;
}
public OnPlayerConnect(playerid){
	Notificacao(playerid, "Conectando", "Voce esta conectando ao servidor!");
	return 1;
}

public OnPlayerText(playerid, text[]){
	Notificacao(playerid, "Ajuda", "Se voce tiver duvidas, use /ajuda!");
	return 1;
}
```
## Resultado: 

![Conectando ao servidor](https://i.imgur.com/r0lrvy5.png)
![Spawnando no servidor](https://i.imgur.com/UPq2oTh.png)
![Chamando OnPlayerText](https://i.imgur.com/nRAUVSH.png)

## Observações finais
* É recomendado utilizar de 0-100 caracteres na mensagem para não ultrapassar a box
* O Sistema gerencia os 3 slots de notificação automaticamente sem a necessidade de escolher, basta chamar a função.
* Chamar a função enquanto existem 3 notificações sendo mostradas ao jogador fará com que a função retorne 0 e falhe.
## Créditos:
* Brazz (Criador da include)
* [Matheus Lima](https://pages.github.com/) (Inspiração & Ajuda com tópico sobre Barras de carregamento)
