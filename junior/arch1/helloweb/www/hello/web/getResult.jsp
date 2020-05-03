<%@ page import="java.util.*" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<%!     public String toTable(Map<String, String> input) {
            StringBuilder sb = new StringBuilder();

            for ( Map.Entry<String, String> entry : input.entrySet() ) {
                sb.append("<tr><td>" + entry.getKey() + "</td><td>" + entry.getValue() + "</td></tr>");
            }

            return sb.toString();
        }
%>
<html>
 <head>
  <title>GETHANDLER</title>
 </head>
 <body>
    <table border="1">
        <tr>
            <th>Параметр</th>
            <th>Значение</th>
        </tr>
        <%= toTable((Map<String, String>)request.getAttribute("sortedMap")) %>
    </body>
</html>