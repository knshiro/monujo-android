package me.ugo.monujo.models;

/**
 * Created by knshiro on 2017/01/15.
 */

public class WalletManager {

    private static WalletManager instance = null;

    public static WalletManager getInstance() {
        if(instance == null) {
            instance = new WalletManager();
        }
        return instance;
    }

    public Wallet createWallet(String path, String password, String language, boolean inTestNet) {
        long walletHandle = createWalletHandle(path, password, language, inTestNet);
        return new Wallet(walletHandle);
    }

    public Wallet openWallet(String path, String password, String language, boolean inTestNet) {
        long walletHandle = openWalletHandle(path, password, inTestNet);
        return new Wallet(walletHandle);
    }

    public Wallet recoveryWallet(String path, String memo, long restoreHeight, boolean inTestNet) {
        long walletHandle = recoveryWalletHandle(path, memo, restoreHeight, inTestNet);
        return new Wallet(walletHandle);
    }

    static {
        System.loadLibrary("libwallet-android");
    }

    private native long createWalletHandle(String path, String password, String language, boolean inTestNet);
    private native long openWalletHandle(String path, String password, boolean inTestNet);
    private native long recoveryWalletHandle(String path, String memo, long restoreHeight, boolean inTestNet);

}