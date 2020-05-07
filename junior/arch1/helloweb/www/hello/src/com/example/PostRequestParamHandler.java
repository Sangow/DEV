package com.example;

import java.util.*;
import java.io.*;

public class PostRequestParamHandler {
    private static final List<String> leftFilds = new ArrayList<>(
                                        List.of("Имя",
                                                "Пол",
                                                "Образование",
                                                "Комментарий",
                                                "Получать спам"));

    private Map<String, String> readyMap;

    public PostRequestParamHandler() {
        this.readyMap = new LinkedHashMap<>();
    }

    public Map<String, String> getReadyTableValues(Map<String, String[]> input) {
        int counter = 0;

        // for ( Map.Entry<String, String[]> entry : input.entrySet() ) {
        //     this.readyMap.put(leftFilds.get(counter), String.join(" ",entry.getValue()));
        //     counter += 1;
        // }

        for ( Map.Entry<String, String[]> entry : input.entrySet() ) {
            switch (entry.getKey()) {
                case "name":
                // try {
                //         FileWriter fr = new FileWriter("/opt/out.txt");
                //         fr.write( String.join(" ", entry.getValue()));
                //         fr.flush();
                //         fr.close();
                //     } catch (IOException e) {
                //         e.printStackTrace();
                //     }
                    readyMap.put("Имя", String.join(" ", entry.getValue()));
                    // readyMap.put("Имя", "Лулу");
                    // try {
                    //     readyMap.put("Имя", new String(String.join(" ", entry.getValue()).getBytes("UTF-8"), "UTF-8"));
                    // } catch (UnsupportedEncodingException e) {
                    //     e.printStackTrace();
                    // }
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