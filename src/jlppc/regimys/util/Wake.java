package jlppc.regimys.util;

public class Wake implements Runnable {
	public Wake() {
		
	}

	@Override
	public void run() {
		notify();
		
	}
	
	
}
