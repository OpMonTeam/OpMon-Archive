package jlppc.regimys.exceptions;

public class IncorrectValueException extends IllegalArgumentException {
	public IncorrectValueException(Object value) {
		super("Valeur incorrecte : " + value.toString());
	}
	
	public IncorrectValueException(Object value, String precisions){
		super("Valeur incorrecte : " + value.toString() + " (" + precisions + ")");
	}
}
