package com.kunpengku;

public class Welcome {

		

	public static void main(String[] args) throws Exception
	{
		Runnable r = new Ppp();
		Thread t = new Thread(r);
		t.start();
		
		//
		Q q = new Q();
		q.start();
		
	}
		
}

class Ppp implements Runnable{
	public void run(){
		try{
			for (int i=0;i<10;i++){
				System.out.println(i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException e){
			e.printStackTrace();
		}
	}
}

class Q extends Thread{
	
	public void run(){
		try{
			for (int i=0;i<10;i++){
				System.out.println(i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException e){
			e.printStackTrace();
		}
		
	}
}
