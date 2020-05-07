package com.example;

import java.util.*;
import java.io.*;

public class PostRequestParamHandler {

    private Map<String, String> readyMap;

    public PostRequestParamHandler() {
        this.readyMap = new LinkedHashMap<>();
    }

    public Map<String, String> getReadyTableValues(Map<String, String[]> input) {
        for ( Map.Entry<String, String[]> entry : input.entrySet() ) {
            switch (entry.getKey()) {
                case "name":
                    readyMap.put("Имя", String.join(" ", entry.getValue()));
                    break;
                case "sex":
                    if (entry.getValue()[0].equals("male")) {
                        readyMap.put("Пол", "Мужской");
                    } else { // female
                        readyMap.put("Пол", "Женский");
                    }
                    break;
                case "education":
                    if (entry.getValue()[0].equals("low")) {
                        readyMap.put("Образование", "Низшее");
                    } else if (entry.getValue()[0].equals("middle")) {
                        readyMap.put("Образование", "Среднее");
                    } else { // high
                        readyMap.put("Образование", "Высшее");
                    }
                    break;
                case "comment":
                    readyMap.put("Комментарий", String.join(" ", entry.getValue()));
                    break;
                case "spam":
                    readyMap.put("Получать спам", "Да");
                    break;
            }
        }

        return this.readyMap;
    }
}