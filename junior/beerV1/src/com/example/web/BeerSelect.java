package com.example.web;

import com.example.model.BeerExpert;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.List;

public class BeerSelect extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        response.setContentType("text/html");

        List expertAdvice = new BeerExpert().getBrands(request.getParameter("color"));

        request.setAttribute("brands", expertAdvice);

        RequestDispatcher view = request.getRequestDispatcher("result.jsp");

        view.forward(request, response);
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        this.doPost(request, response);
    }
}