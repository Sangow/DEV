<%@ page import="java.util.*" %>
<%@ page contentType="text/html" %>

<html>
    <head>
        <title>COOKIE</title>
    </head>
    <body>
        <%= "page_visits=" + String.valueOf(request.getAttribute("page_visits")) %>
    </body>
</html>