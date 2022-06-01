modded class ItemBase
{

	/* Switch 
	Utilizar quando queremos comparar a mesma variável ou expressão com várias opções.
	A instrução switch é similar a uma série de instruções IF sobre a mesma expressão. 
	Em muitas ocasiões, você pode querer comparar a mesma variável (ou expressão) com muitos valores diferentes, 
	executando uma peça diferente do código dependendo de qual valor ele se encaixar. Este é exatamente o que a instrução switch faz. 
	https://docs.microsoft.com/pt-br/dotnet/csharp/language-reference/operators/boolean-logical-operators

	bool
	https://docs.microsoft.com/pt-br/dotnet/csharp/language-reference/builtin-types/bool
	*/


	//Encaixes Para itens verticais como paredes portoes e portas
	bool EncaixeVertical = false;
	bool EncaixeVertical()
	{
		return EncaixeVertical;
	}
	void DefineEncaixeVertical(bool a)
	{
		EncaixeVertical = a;
	}
	vector PegarPontosEncaixeVertical()
	{
		vector pos = "0 0 0";
		switch(PontosEncaixeVertical)
		{
			case 0:
			pos = GetMemoryPointPos( "Snapping1" );
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos( "Snapping2" );
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos( "Snapping3" );
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos( "Snapping4" );
			return ModelToWorld( pos );
			break;
			
			case 4:
			pos = GetMemoryPointPos( "Snapping5" );
			return ModelToWorld( pos );
			break;
			
			case 5:
			pos = GetMemoryPointPos( "Snapping6" );
			return ModelToWorld( pos );
			break;
			
			case 6:
			pos = GetMemoryPointPos( "Snapping7" );
			return ModelToWorld( pos );
			break;

			case 7:
			pos = GetMemoryPointPos( "Snapping8" );
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos( "Snapping1" );
		return ModelToWorld( pos );
	}
	//Encaixes Para itens horizontais como chao, teto, chao com porta...
	bool EncaixeHorizontal = false;
	bool EncaixeHorizontal()
	{
		return EncaixeHorizontal;
	}
	void DefineEncaixeHotizontal(bool b)
	{
		EncaixeHorizontal = b;
	}
	vector PegarPontosEncaixeHorizontal()
	{
		vector pos = "0 0 0";
		switch(PontosEncaixeHorizontal)
		{
			case 0:
			pos = GetMemoryPointPos( "SnappingFloor1" );
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos( "SnappingFloor2" );
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos( "SnappingRoof1" );
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos( "SnappingRoof2" );
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos( "SnappingFloor1" );
		return ModelToWorld( pos );
	}
	//Encaixes Para itens verticais especificos como pilares, postes...
	bool EncaixeVerticalPilares = false;
	bool EncaixeVerticalPilares()
	{
		return EncaixeVerticalPilares;
	}
	void DefineEncaixeVerticalPilares(bool c)
	{
		EncaixeVerticalPilares = c;
	}
	vector PegarPontosEncaixeVerticalPilares()
	{
		vector pos = "0 0 0";
		switch(PontosEncaixeVerticalPilares)
		{
			case 0:
			pos = GetMemoryPointPos( "snappingpillar1" );
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos( "snappingpillar2" );
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos( "snappingpillar3" );
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos( "snappingpillar4" );
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos( "snappingpillar1" );
		return ModelToWorld( pos );
	}
	//Encaixes Para itens Horizontais especificos como fundações, bunkers....
	bool EncaixeHorizontalFundacao = false;
	bool EncaixeHorizontalFundacao()
	{
		return EncaixeHorizontalFundacao;
	}
	void DefineEncaixeHorizontalFundacao(bool d)
	{
		EncaixeHorizontalFundacao = d;
	}
	vector PegarPontosEncaixeHorizontalFundacao()
	{
		vector pos = "0 0 0";
		switch(PontosEncaixeHorizontalFundacao)
		{
			case 0:
			pos = GetMemoryPointPos( "snappingfoundation1" );
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos( "snappingfoundation2" );
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos( "snappingfoundation3" );
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos( "snappingfoundation4" );
			return ModelToWorld( pos );
			break;

			case 4:
			pos = GetMemoryPointPos( "snappingfoundation5" );
			return ModelToWorld( pos );
			break;

			case 5:
			pos = GetMemoryPointPos( "snappingfoundation6" );
			return ModelToWorld( pos );
			break;

			case 6:
			pos = GetMemoryPointPos( "snappingfoundation7" );
			return ModelToWorld( pos );
			break;

			case 7:
			pos = GetMemoryPointPos( "snappingfoundation8" );
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos( "snappingfoundation1" );
		return ModelToWorld( pos );
	}
	
	//Definiçao verdadeiro ou flata para setar como ferramenta Admin
	bool isExdAdminTool()
	{
		return false;
	}
	//Permiti que os Itens tenham a possibilidade de agarrar
	bool OpcaoDeAgarrar()
	{
		return false;
	}

	/* Setar a açao na base dos itens faz com que qualquer item adicionado ao .json possa ser usado como ferramenta de raid, 
	des que seja derivado do class ItemBase.
	Ainda nao testei se pode ocorrer bugs ou crash.
	Lembrete */
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDestroyPart);
	}
}
