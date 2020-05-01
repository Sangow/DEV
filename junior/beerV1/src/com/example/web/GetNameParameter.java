package com.example.web;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Cookie;

import java.io.IOException;

public class GetNameParameter extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        response.setContentType("text/html");

        Cookie cookie = new Cookie("username", request.getParameter("username"));

        // cookie.setMaxAge(20*60);

        response.addCookie(cookie);

        request.getRequestDispatcher("cookieresult.jsp").forward(request, response);
    }
}