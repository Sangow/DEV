package com.example.web;

import javax.servlet.http.HttpSessionListener;
import javax.servlet.http.HttpSessionEvent;

public class BeerSessionCounter implements HttpSessionListener {

    static private int activeSessions;

    public static int getActiveSessions() {
        return activeSessions;
    }

    public void sessionCreated(HttpSessionEvent event) {
        activeSessions++;
        // System.out.println("New Beer Session.");
    }

    public void sessionDestroyed(HttpSessionEvent event) {
        activeSessions--;
        // System.out.println("Beer Session Destroyed.");
    }
}