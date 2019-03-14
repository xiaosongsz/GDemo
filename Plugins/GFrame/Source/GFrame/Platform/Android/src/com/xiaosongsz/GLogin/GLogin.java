package com.xiaosongsz.GLogin;

import com.xiaosongsz.GPlatform.GPlatform;
import com.xiaosongsz.GPlatform.IGPlatform;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;

public class GLogin extends HashMap<String, IGLogin> implements IGPlatform {
    public static final String TAG = "GLogin";

    private static final String Login = "Login";
    private static final String Logout = "Logout";
    private static final String LoginChannel = "LoginChannel";

    protected static GLogin instance = null;
    protected static GLogin getInstance(){
        if (instance == null){
            instance = new GLogin();
        }
        return instance;
    }

    private GLogin(){
        GPlatform.getInstance().put(TAG, this);
    }

    public void loginResult(JSONObject result){
        try {
            JSONObject message = new JSONObject();
            message.put(GPlatform.Head, Login);
            message.put(GPlatform.Body, result);
            GPlatform.getInstance().sendMessage(TAG, message);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    public void logoutResult(JSONObject result){
        try {
            JSONObject message = new JSONObject();
            message.put(GPlatform.Head, Logout);
            message.put(GPlatform.Body, result);
            GPlatform.getInstance().sendMessage(TAG, message);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    @Override
    public JSONObject receiveMessage(JSONObject message) {
        try {
            String head = message.getString(GPlatform.Head);
            JSONObject body = message.getJSONObject(GPlatform.Body);
            switch (head){
                case Login:
                    login(body);
                    break;
                case Logout:
                    logout(body);
                    break;
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return null;
    }

    protected void login(JSONObject login){
        try {
            String loginChannel = login.getString(LoginChannel);
            if (containsKey(loginChannel)){
                IGLogin igLogin = get(loginChannel);
                igLogin.login(login);
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    protected void logout(JSONObject logout){
        try {
            String loginChannel = logout.getString(LoginChannel);
            if (containsKey(loginChannel)){
                IGLogin igLogin = get(loginChannel);
                igLogin.logout(logout);
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }
}
