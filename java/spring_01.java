package com.kpk.learnSpring;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class DemoHello {
	public static void main(String[] args) {
       	
		ApplicationContext ac = new ClassPathXmlApplicationContext("applicationContext.xml");
		hellobean  hl = (hellobean) ac.getBean("helloworld");
		System.out.println(hl.getHelloWorld());
	}
}
