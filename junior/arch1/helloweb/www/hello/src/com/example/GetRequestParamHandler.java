package com.example;

import java.util.Map;
import java.util.TreeMap;

class GetRequestSorter {
    private Map<String, String> readyMap;

    GetRequestSorter() {
        this.readyMap = new TreeMap<>();
    }

    public Map<String, String> getReadyTableValues(Map<String, String[]> input) {
        for ( Map.Entry<String, String[]> entry : input.entrySet() ) {
            this.readyMap.put(entry.getKey(), String.join(" ", entry.getValue()));
        }
        return this.readyMap;
    }
}