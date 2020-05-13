package com.example.web;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Cookie;

import java.io.IOException;
import java.io.PrintWriter;

public class CheckCookie extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        response.setContentType("text/html");
        PrintWriter pr = response.getWriter();

        Cookie[] cookies = request.getCookies();

        for ( int i = 0; i < cookies.length; i++ ) {
            Cookie cookie = cookies[i];

            if ( cookie.getName().equals("username") ) {
                pr.println("Hello " + cookie.getValue());
                break;
            } 
            if ( cookie.getName().equals("JSESSIONID") ) {
                pr.println( cookie.getMaxAge() );
            }
        }
    }
}