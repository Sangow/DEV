package com.example;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;

public class CookieSetServlet extends HttpServlet {
    public void doGet(HttpServletRequest request,
        HttpServletResponse response)
        throws IOException, ServletException {

        response.setContentType("text/html");

        boolean isSet = false;
        int page_visits = 1;

        Cookie[] cookies = request.getCookies();

        if ( cookies != null ) {
            for ( Cookie c : cookies ) {
                if ( c.getName().equals("page_visits") ) {
                    page_visits = 1 + Integer.parseInt(c.getValue());
                    c.setValue(String.valueOf(page_visits));
                    response.addCookie(c);
                    isSet = true;
                    break;
                }
            }
        }


        if ( !isSet ) {
            response.addCookie(new Cookie("page_visits", "1"));
        }

        request.setAttribute("page_visits", page_visits);
        request.getRequestDispatcher("/cookie.jsp").forward(request, response);
    }
}