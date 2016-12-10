package jlppc.regimys.exceptions;
/**
 * Exception lancée dans le cas d'une valeur incorrecte (Un null non voulu, une valeur inferieure a 0 alors qu'il faut un nombre positif etc...)
 * @author Jlppc
 *
 */
public class IncorrectValueException extends IllegalArgumentException {
	public IncorrectValueException(Object value) {
		super("Valeur incorrecte : " + value.toString());
	}
	
	public IncorrectValueException(Object value, String precisions){
		super("Valeur incorrecte : " + value.toString() + " (" + precisions + ")");
	}
}
