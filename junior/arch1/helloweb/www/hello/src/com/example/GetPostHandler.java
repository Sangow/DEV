package com.example;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;

public class GetPostHandler extends HttpServlet {
    public void doGet(HttpServletRequest request,
        HttpServletResponse response)
        throws IOException, ServletException {

        request.setAttribute("tableKeyValues", new GetRequestParamHandler().getReadyTableValues(request.getParameterMap()));

        request.getRequestDispatcher("/result.jsp").forward(request, response);
    }

    public void doPost(HttpServletRequest request,
        HttpServletResponse response)
        throws IOException, ServletException {

        request.setCharacterEncoding("UTF-8"); // cirilic won`t work wothout this line https://balusc.omnifaces.org/2009/05/unicode-how-to-get-characters-right.html
        request.setAttribute("tableKeyValues", new PostRequestParamHandler().getReadyTableValues(request.getParameterMap()));

        request.getRequestDispatcher("/result.jsp").forward(request, response);
    }
}