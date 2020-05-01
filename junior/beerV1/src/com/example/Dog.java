package com.example;

import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionBindingEvent;
import javax.servlet.http.HttpSessionBindingListener;
import javax.servlet.http.HttpSessionActivationListener;
import java.io.*;

public class Dog implements HttpSessionBindingListener,
                            HttpSessionActivationListener,
                            Serializable {

    private String breed;

    public Dog(String br) {
        this.breed = br;
    }

    public String getBreed() {
        return this.breed;
    }

    public void valueBound(HttpSessionBindingEvent event) {
        // System.out.println("Dog included in session");
        this.breed = "BOUNDED";
    }

    public void valueUnbound(HttpSessionBindingEvent event) {
        // System.out.println("Dog Excluded from session");
    }

    public void sessionWillPassivate(HttpSessionEvent event) {}

    public void sessionDidActivate(HttpSessionEvent event) {}

    public String toString() {
       return "Dog{" + "breed=" + this.breed + "}";
   }
}