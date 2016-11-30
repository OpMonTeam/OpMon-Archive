package jlppc.regimys.evolution;

import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.WIP;
/**Classe permettant de definir une évolution par lieu. N'est pas encore fonctionnel puisque les endroits ne sont pas encore présents
 * @author jlppc*/
@WIP
public class E_Land extends Evolution {
	
	Object carteDuLieu;//Pour l'instant, cet objet est de type Object, car la classe permettant de determiner le lieu n'est pas crée.
	
	public E_Land(int evo, Object carteDuLieu) {
		super(evo);
		this.carteDuLieu = carteDuLieu;
	}

	@Override
	public boolean checkEvolve(Pokemon toCheck) {
		//Checker l'endroit ou se trouve le dresseur qui a le pokemon
		return false;
	}
}
