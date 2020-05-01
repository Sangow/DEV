package com.example;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class ListenerTester extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response)
                        throws IOException, ServletException {
        response.setContentType("text/html");

        PrintWriter pr = response.getWriter();

        pr.println("test context attributes set by listener<br>");
        pr.println("<br>");

        HttpSession session = request.getSession();

        if ( session.isNew() ) {
            session.setAttribute("dig", new Dog("zalupa"));

            Dog dog = (Dog) getServletContext().getAttribute("dog");
            pr.println("Dog's breed is: " + dog.getBreed());
        }else {
            Dog dog = (Dog) session.getAttribute("dig");
            pr.println("Dog's breed is: " + dog.getBreed());
        }

        // Dog dig = new Dog("zalupa");

        // request.getSession().setAttribute("dig", dig);

        // request.getSession().setAttribute("dig", new Dog("zalupa"));

        // Dog dog = (Dog) getServletContext().getAttribute("dig");

        // pr.println("Dog's breed is: " + dog.getBreed());
    }
}