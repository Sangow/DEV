package foo;

import java.io.IOException;

import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import foo.HobbyStorage;

public class Hobby extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        // List hobbyNames = new HobbyStorage().getHobbyNames(request.getParameter("hobby"));
        List hobbyNames = new HobbyStorage().getHobbyNames(request.getParameter("hobby"));

        request.setAttribute("names",hobbyNames);

        request.getRequestDispatcher("result.jsp").forward(request, response);
    }
}