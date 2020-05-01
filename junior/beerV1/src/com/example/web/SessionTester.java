package com.example.web;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Cookie;

import java.io.IOException;
import java.io.PrintWriter;

public class SessionTester extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        response.setContentType("text/html");

        PrintWriter pr = response.getWriter();

        pr.println("TEST SESSION ATTRIUTES<br>");

        // HttpSession hs = request.getSession();

        // response.sendRedirect("/Beer-v1/ListenTest.do");

        if ( request.getSession().isNew() ) {
            pr.println("This is new session!<br>");
            pr.println("<html><body>");
            pr.println("<a href=\"" + response.encodeURL("/Beer-v1/ListenTest.do") + "\">click me</a>");
            pr.println("</body></html>");
        } else {
            Cookie[] cook = request.getCookies();

            for ( int i = 0; i < cook.length; i++ ) {
                Cookie cookie = cook[i];

                if ( cookie.getName().equals("username") ) {
                    pr.println("Hello " + cookie.getValue());
                    break;
                }
            }
            // pr.println("<html><body>");
            // pr.println(request.getSession().getId());
            // pr.println("</body></html>");
        }

        Cookie cookie = new Cookie("username", "ZALUPA");
        cookie.setMaxAge(20*60);

        response.addCookie(cookie);
    }
}