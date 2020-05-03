package com.example;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;

    public class GetHandler extends HttpServlet {
        public void doGet(HttpServletRequest request,
            HttpServletResponse response)
            throws IOException, ServletException {

            request.setAttribute("sortedMap", new RequestSorter().getReadyTableValues(request.getParameterMap()));

            request.getRequestDispatcher("getResult.jsp").forward(request, response);
        }
}