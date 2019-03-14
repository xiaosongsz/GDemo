package com.xiaosongsz.GPlatform;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;

public class GPlatform extends HashMap<String, IGPlatform> {
    public static final String TAG = "GPlatform";

    public static final String Head = "Head";
    public static final String Body = "Body";

    protected static GPlatform instance = null;
    public static GPlatform getInstance(){
        if (instance == null){
            instance = new GPlatform();
        }
        return instance;
    }

    private GPlatform(){

    }

    public static native void nativeJava2C(final String head, final String message);

    public static String nativeC2Java(final String head, final String message){
        return GPlatform.getInstance().receiveMessage(head, message);
    }

    String receiveMessage(String Head, String message){
        IGPlatform platform = get(Head);
        if (platform != null){
            try {
                JSONObject jsonObject = new JSONObject(message);
                JSONObject retObject = platform.receiveMessage(jsonObject);
                return retObject.toString();
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        return "";
    }

    public void sendMessage(String head, JSONObject message){
        nativeJava2C(head, message.toString());
    }
}
