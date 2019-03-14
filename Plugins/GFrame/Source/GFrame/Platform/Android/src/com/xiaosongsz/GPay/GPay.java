package com.xiaosongsz.GPay;

import com.xiaosongsz.GPlatform.GPlatform;
import com.xiaosongsz.GPlatform.IGPlatform;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;

public class GPay extends HashMap<String, IGPay> implements IGPlatform {
    public static final String TAG = "GPay";

    private static final String Pay = "Pay";
    private static final String PayResult = "PayResult";
    private static final String PayChannel = "PayChannel";
    
    protected static GPay instance = null;
    public static GPay getInstance(){
        if (instance == null){
            instance = new GPay();
        }
        return instance;
    }

    private GPay(){
        GPlatform.getInstance().put(TAG, this);
    }

    @Override
    public JSONObject receiveMessage(JSONObject message) {

        try {
            String head = message.getString(GPlatform.Head);
            switch (head){
                case Pay:
                    pay(message.getJSONObject(GPlatform.Body));
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }

        return null;
    }

    public void payResult(JSONObject payResult){
        JSONObject message = new JSONObject();
        try {
            message.put(GPlatform.Head, PayResult);
            message.put(GPlatform.Body, payResult);

            GPlatform.getInstance().sendMessage(TAG, message);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    protected void pay(JSONObject payItem){
        try {
            String payChannel = payItem.getString(PayChannel);
            if (containsKey(payChannel)){
                IGPay igPay = get(payChannel);
                igPay.pay(payItem);
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }
}
