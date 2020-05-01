<%@ page import="java.util.*" %>
<html>
    <body>
        <h1 align="center">Beer Recommendations
        <p>

        <%
            List styles = (List)request.getAttribute("brands");

            Iterator it = styles.iterator();
                
            while ( it.hasNext() ) {
                out.print("<br>try: " + it.next());
            }
        %>
    </body>
</html>