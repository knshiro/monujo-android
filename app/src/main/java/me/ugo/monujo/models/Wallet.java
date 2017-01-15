package me.ugo.monujo.models;

/**
 * Created by knshiro on 2017/01/15.
 */

public class Wallet {

    public Wallet(Long handle) {
        initialize(handle);
    }

    // new code
    static {
        System.loadLibrary("libwallet-android");
    }
    public native String initialize(Long handle);

    public native String getAddress();
}
