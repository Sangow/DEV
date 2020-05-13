package com.example.web;

import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionBindingEvent;

public class AttributeSessionListener implements HttpSessionAttributeListener {

    public void attributeAdded(HttpSessionBindingEvent event) {
        System.out.println("Attribute added: " + event.getName() + "->" + event.getValue());
    }

    public void attributeRemoved(HttpSessionBindingEvent event) {
        System.out.println("Attribute removed: " + event.getName() + "->" + event.getValue());
    }

    public void attributeReplaced(HttpSessionBindingEvent event) {
        System.out.println("Attribute replaced: " + event.getName() + "->" + event.getValue());
    }
}