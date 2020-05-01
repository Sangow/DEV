import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

    public class HelloStart extends HttpServlet {
        public void doGet(HttpServletRequest request,
                HttpServletResponse response)
                    throws IOException {
            PrintWriter out = response.getWriter();
            out.println("<html><body><h1 align=center>Hello Web!</h1><br>" + new java.util.Date() + "</body></html>");
        }
    }