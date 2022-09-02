/*Criado Por: Marcos Brazz(Brazz)
	~~~~~~~ Funções ~~~~~~
	native Notificacao(playerid, const titulo[], const mensagem[]);

	~~ Parametros:
	~~ 	playerid: playerid;
	~~ 	titulo: titulo da notificação
	~~ 	mensagem: mensagem da notificação (Recomendado até 80-100 caracteres, mais que isso pode exeder a borda da box)
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~~ Retornos:
	~~ 0 = Função não foi executada/Exedeu as 3 notificações ao mesmo tempo
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Observações:
	-> O Sistema pode criar até 3 notificações ao mesmo tempo
	-> O Sistema analisa as variaveis para criar as 3 notificações automaticamente,
	ou seja, Voce pode chamar a função Notificacao(...) varias vezes ao mesmo tempo. 
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	

*/



#tryinclude <a_samp>
//Declaração das Variaveis da Textdraw
new 
	Text:TxDWarn_1,
	PlayerText:TxDWarnP_1[MAX_PLAYERS][3],
	Text:TxDWarn_2,
	PlayerText:TxDWarnP_2[MAX_PLAYERS][3],
	Text:TxDWarn_3,
	PlayerText:TxDWarnP_3[MAX_PLAYERS][3];

//Variaveis Necessárias
//notification-system (NTS)
#define Brazz_MAX_NOTIFICATIONS 	(3) //Não coloque numeros acima de 3

new
	Brazz_BarUsed[MAX_PLAYERS][Brazz_MAX_NOTIFICATIONS] = {-1, ...},
	Float:Brazz_BarPercent[MAX_PLAYERS][Brazz_MAX_NOTIFICATIONS] = {100.0, ...};

stock Notificacao(playerid, titulo[], mensagem[]) return __chamarBarra(playerid, titulo, mensagem);
public OnGameModeInit()
{
	// Don't use these lines if it's a filterscript
	TxDWarn_1 = TextDrawCreate(563.000000, 306.000000, "_");
	TextDrawFont(TxDWarn_1, 1);
	TextDrawLetterSize(TxDWarn_1, 0.600000, 6.450007);
	TextDrawTextSize(TxDWarn_1, 298.500000, 75.000000);
	TextDrawSetOutline(TxDWarn_1, 1);
	TextDrawSetShadow(TxDWarn_1, 0);
	TextDrawAlignment(TxDWarn_1, 2);
	TextDrawColor(TxDWarn_1, -1);
	TextDrawBackgroundColor(TxDWarn_1, 255);
	TextDrawBoxColor(TxDWarn_1, 135);
	TextDrawUseBox(TxDWarn_1, 1);
	TextDrawSetProportional(TxDWarn_1, 1);
	TextDrawSetSelectable(TxDWarn_1, 0);


	TxDWarn_2 = TextDrawCreate(563.000000, 241.000000, "_");
	TextDrawFont(TxDWarn_2, 1);
	TextDrawLetterSize(TxDWarn_2, 0.600000, 6.450007);
	TextDrawTextSize(TxDWarn_2, 298.500000, 75.000000);
	TextDrawSetOutline(TxDWarn_2, 1);
	TextDrawSetShadow(TxDWarn_2, 0);
	TextDrawAlignment(TxDWarn_2, 2);
	TextDrawColor(TxDWarn_2, -1);
	TextDrawBackgroundColor(TxDWarn_2, 255);
	TextDrawBoxColor(TxDWarn_2, 135);
	TextDrawUseBox(TxDWarn_2, 1);
	TextDrawSetProportional(TxDWarn_2, 1);
	TextDrawSetSelectable(TxDWarn_2, 0);


	TxDWarn_3 = TextDrawCreate(563.000000, 177.000000, "_");
	TextDrawFont(TxDWarn_3, 2);
	TextDrawLetterSize(TxDWarn_3, 0.600000, 6.450007);
	TextDrawTextSize(TxDWarn_3, 298.500000, 75.000000);
	TextDrawSetOutline(TxDWarn_3, 1);
	TextDrawSetShadow(TxDWarn_3, 0);
	TextDrawAlignment(TxDWarn_3, 2);
	TextDrawColor(TxDWarn_3, -1);
	TextDrawBackgroundColor(TxDWarn_3, 255);
	TextDrawBoxColor(TxDWarn_3, 135);
	TextDrawUseBox(TxDWarn_3, 1);
	TextDrawSetProportional(TxDWarn_3, 1);
	TextDrawSetSelectable(TxDWarn_3, 0);
	#if defined nsb_OnGameModeInit
		return nsb_OnGameModeInit();
	#else
		return 1;
	#endif
}

public OnGameModeExit()
{
	
	#if defined nsb_OnGameModeExit
		return nsb_OnGameModeExit();
	#else
		return 1;
	#endif
}



stock __chamarBarra(playerid, titulo[], mensagem[]) {
	new
	bar_index = __getBarUnused(playerid);
	if(bar_index != -1){
		__mostrarBarra(playerid, bar_index, titulo, mensagem);
		Brazz_BarPercent[playerid][bar_index] = 100.0;
		Brazz_BarUsed[playerid][bar_index] = 1;
		SetTimerEx("moverBarrinha", 100, 0, "id", playerid, bar_index);
		return 1;
	}
	return 0;
}
stock __getBarUnused(playerid){
	for(new i; i < Brazz_MAX_NOTIFICATIONS; i++){
		if(Brazz_BarUsed[playerid][i] == -1) return i;
	}
	return -1;
}
stock __mostrarBarra(playerid, bar_index, titulo[] = "", mensagem[] = "") {
	switch(bar_index) {
		case 0: {

			PlayerTextDrawSetString(playerid, TxDWarnP_1[playerid][1], titulo);
			PlayerTextDrawSetString(playerid, TxDWarnP_1[playerid][2], mensagem);
			TextDrawShowForPlayer(playerid, TxDWarn_1);
			for(new i; i < sizeof(TxDWarnP_1[]); i++){
				PlayerTextDrawShow(playerid, TxDWarnP_1[playerid][i]);
			}
		}
		case 1: {
			PlayerTextDrawSetString(playerid, TxDWarnP_2[playerid][1], titulo);
			PlayerTextDrawSetString(playerid, TxDWarnP_2[playerid][2], mensagem);
			TextDrawShowForPlayer(playerid, TxDWarn_2);
			for(new i; i < sizeof(TxDWarnP_2[]); i++){
				PlayerTextDrawShow(playerid, TxDWarnP_2[playerid][i]);
			}
		}
		case 2: {
			PlayerTextDrawSetString(playerid, TxDWarnP_3[playerid][1], titulo);
			PlayerTextDrawSetString(playerid, TxDWarnP_3[playerid][2], mensagem);
			TextDrawShowForPlayer(playerid, TxDWarn_3);
			for(new i; i < sizeof(TxDWarnP_3[]); i++){
				PlayerTextDrawShow(playerid, TxDWarnP_3[playerid][i]);
			}
		}
	}
}
stock __ocultarBarra(playerid, bar_index) {
	switch(bar_index) {
		case 0: {

			PlayerTextDrawSetString(playerid, TxDWarnP_1[playerid][1], "_");
			PlayerTextDrawSetString(playerid, TxDWarnP_1[playerid][2], "_");
			TextDrawHideForPlayer(playerid, TxDWarn_1);
			for(new i; i < sizeof(TxDWarnP_1[]); i++){
				PlayerTextDrawHide(playerid, TxDWarnP_1[playerid][i]);
			}
		}
		case 1: {
			PlayerTextDrawSetString(playerid, TxDWarnP_2[playerid][1], "_");
			PlayerTextDrawSetString(playerid, TxDWarnP_2[playerid][2], "_");
			TextDrawHideForPlayer(playerid, TxDWarn_2);
			for(new i; i < sizeof(TxDWarnP_2[]); i++){
				PlayerTextDrawHide(playerid, TxDWarnP_2[playerid][i]);
			}
		}
		case 2: {
			PlayerTextDrawSetString(playerid, TxDWarnP_3[playerid][1], "_");
			PlayerTextDrawSetString(playerid, TxDWarnP_3[playerid][2], "_");
			TextDrawHideForPlayer(playerid, TxDWarn_3);
			for(new i; i < sizeof(TxDWarnP_3[]); i++){
				PlayerTextDrawHide(playerid, TxDWarnP_3[playerid][i]);
			}
		}
	}
}
forward moverBarrinha(playerid, bar_index);
public moverBarrinha(playerid, bar_index){
	if(Brazz_BarPercent[playerid][bar_index] > 0.0){
		Brazz_BarPercent[playerid][bar_index] -= 1.0;
		new Float:base = 0.79;
		new Float:bar = (Brazz_BarPercent[playerid][bar_index]*base);


		switch(bar_index) {
			case 0: {

				PlayerTextDrawTextSize(playerid, TxDWarnP_1[playerid][0], 521+bar, 75.000000);
				PlayerTextDrawShow(playerid, TxDWarnP_1[playerid][0]);
			}
			case 1: {
				PlayerTextDrawTextSize(playerid, TxDWarnP_2[playerid][0], 521+bar, 75.000000);
				PlayerTextDrawShow(playerid, TxDWarnP_2[playerid][0]);
			}
			case 2: {
				PlayerTextDrawTextSize(playerid, TxDWarnP_3[playerid][0], 521+bar, 75.000000);
				PlayerTextDrawShow(playerid, TxDWarnP_3[playerid][0]);
			}
		}
		
		SetTimerEx("moverBarrinha", 100, 0, "ii", playerid, bar_index);
	}else {
		Brazz_BarUsed[playerid][bar_index] = -1;
		Brazz_BarPercent[playerid][bar_index] = 100.0;
		__ocultarBarra(playerid, bar_index);
	}
}
public OnPlayerDisconnect(playerid, reason){
	#if defined nsb_OnPlayerConnect
		return nsb_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
public OnPlayerConnect(playerid){
	for(new i; i < Brazz_MAX_NOTIFICATIONS; i++){
		Brazz_BarPercent[playerid][i] = 100.0;
		Brazz_BarUsed[playerid][i] = -1;
	}
	TxDWarnP_1[playerid][0] = CreatePlayerTextDraw(playerid, 525.000000, 362.000000, "_");
	PlayerTextDrawFont(playerid, TxDWarnP_1[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_1[playerid][0], 0.304166, 0.200003);
	PlayerTextDrawTextSize(playerid, TxDWarnP_1[playerid][0], 600.500000, 75.000000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_1[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_1[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_1[playerid][0], 1);
	PlayerTextDrawColor(playerid, TxDWarnP_1[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_1[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_1[playerid][0], 1097458175);
	PlayerTextDrawUseBox(playerid, TxDWarnP_1[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_1[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_1[playerid][0], 0);

	TxDWarnP_1[playerid][1] = CreatePlayerTextDraw(playerid, 564.000000, 307.000000, "titulo");
	PlayerTextDrawFont(playerid, TxDWarnP_1[playerid][1], 2);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_1[playerid][1], 0.204166, 1.100000);
	PlayerTextDrawTextSize(playerid, TxDWarnP_1[playerid][1], 400.000000, 75.500000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_1[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_1[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_1[playerid][1], 2);
	PlayerTextDrawColor(playerid, TxDWarnP_1[playerid][1], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_1[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_1[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, TxDWarnP_1[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_1[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_1[playerid][1], 0);


	TxDWarnP_1[playerid][2] = CreatePlayerTextDraw(playerid, 530.000000, 321.000000, "brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao ");
	PlayerTextDrawFont(playerid, TxDWarnP_1[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_1[playerid][2], 0.150000, 0.800000);
	PlayerTextDrawTextSize(playerid, TxDWarnP_1[playerid][2], 599.000000, 112.000000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_1[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_1[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_1[playerid][2], 1);
	PlayerTextDrawColor(playerid, TxDWarnP_1[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_1[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_1[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, TxDWarnP_1[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_1[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_1[playerid][2], 0);



	TxDWarnP_2[playerid][0] = CreatePlayerTextDraw(playerid, 525.000000, 296.000000, "_");
	PlayerTextDrawFont(playerid, TxDWarnP_2[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_2[playerid][0], 0.304166, 0.200003);
	PlayerTextDrawTextSize(playerid, TxDWarnP_2[playerid][0], 600.500000, 75.000000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_2[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_2[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_2[playerid][0], 1);
	PlayerTextDrawColor(playerid, TxDWarnP_2[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_2[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_2[playerid][0], 1097458175);
	PlayerTextDrawUseBox(playerid, TxDWarnP_2[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_2[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_2[playerid][0], 0);

	TxDWarnP_2[playerid][1] = CreatePlayerTextDraw(playerid, 564.000000, 243.000000, "titulo");
	PlayerTextDrawFont(playerid, TxDWarnP_2[playerid][1], 2);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_2[playerid][1], 0.204166, 1.100000);
	PlayerTextDrawTextSize(playerid, TxDWarnP_2[playerid][1], 400.000000, 75.500000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_2[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_2[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_2[playerid][1], 2);
	PlayerTextDrawColor(playerid, TxDWarnP_2[playerid][1], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_2[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_2[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, TxDWarnP_2[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_2[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_2[playerid][1], 0);

	TxDWarnP_2[playerid][2] = CreatePlayerTextDraw(playerid, 530.000000, 254.000000, "brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao ");
	PlayerTextDrawFont(playerid, TxDWarnP_2[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_2[playerid][2], 0.150000, 0.800000);
	PlayerTextDrawTextSize(playerid, TxDWarnP_2[playerid][2], 599.000000, 112.000000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_2[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_2[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_2[playerid][2], 1);
	PlayerTextDrawColor(playerid, TxDWarnP_2[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_2[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_2[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, TxDWarnP_2[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_2[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_2[playerid][2], 0);


	TxDWarnP_3[playerid][0] = CreatePlayerTextDraw(playerid, 525.000000, 232.000000, "_");
	PlayerTextDrawFont(playerid, TxDWarnP_3[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_3[playerid][0], 0.304166, 0.200003);
	PlayerTextDrawTextSize(playerid, TxDWarnP_3[playerid][0], 600.500000, 75.000000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_3[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_3[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_3[playerid][0], 1);
	PlayerTextDrawColor(playerid, TxDWarnP_3[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_3[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_3[playerid][0], 1097458175);
	PlayerTextDrawUseBox(playerid, TxDWarnP_3[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_3[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_3[playerid][0], 0);

	TxDWarnP_3[playerid][1] = CreatePlayerTextDraw(playerid, 564.000000, 176.000000, "titulo");
	PlayerTextDrawFont(playerid, TxDWarnP_3[playerid][1], 2);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_3[playerid][1], 0.204166, 1.100000);
	PlayerTextDrawTextSize(playerid, TxDWarnP_3[playerid][1], 400.000000, 75.500000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_3[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_3[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_3[playerid][1], 2);
	PlayerTextDrawColor(playerid, TxDWarnP_3[playerid][1], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_3[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_3[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, TxDWarnP_3[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_3[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_3[playerid][1], 0);

	TxDWarnP_3[playerid][2] = CreatePlayerTextDraw(playerid, 530.000000, 188.000000, "brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao brazz lindao ");
	PlayerTextDrawFont(playerid, TxDWarnP_3[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, TxDWarnP_3[playerid][2], 0.150000, 0.800000);
	PlayerTextDrawTextSize(playerid, TxDWarnP_3[playerid][2], 599.000000, 112.000000);
	PlayerTextDrawSetOutline(playerid, TxDWarnP_3[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, TxDWarnP_3[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, TxDWarnP_3[playerid][2], 1);
	PlayerTextDrawColor(playerid, TxDWarnP_3[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, TxDWarnP_3[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, TxDWarnP_3[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, TxDWarnP_3[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, TxDWarnP_3[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, TxDWarnP_3[playerid][2], 0);

	#if defined nsb_OnPlayerConnect
		return nsb_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

//~~~~~~~~~ HOOKS ~~~~~~~//

//~~~~~~~~~ Hook OnPlayerConnect ~~~~~~~//
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
 
#define OnPlayerConnect nsb_OnPlayerConnect
#if defined nsb_OnPlayerConnect
	forward nsb_OnPlayerConnect(playerid);
#endif


//~~~~~~~~~ Hook OnGameModeInit ~~~~~~~//
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
 
#define OnGameModeInit nsb_OnGameModeInit
#if defined nsb_OnGameModeInit
	forward nsb_OnGameModeInit();
#endif

	//~~~~~~~~~ Hook OnPlayerDisconnect ~~~~~~~//
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
 
#define OnPlayerDisconnect nsb_OnPlayerDisconnect
#if defined nsb_OnPlayerDisconnect
	forward nsb_OnPlayerDisconnect(playerid);
#endif


//~~~~~~~~~ Hook OnGameModeInit ~~~~~~~//
#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
 
#define OnGameModeExit nsb_OnGameModeExit
#if defined nsb_OnGameModeExit
	forward nsb_OnGameModeExit();
#endif