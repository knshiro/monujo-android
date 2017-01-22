#include <jni.h>

#include <wallet/wallet2_api.h>
#include "handle.h"

JNIEXPORT void JNICALL
Java_me_ugo_monujo_models_Wallet_initialize(JNIEnv *env, jobject instance, jlong handle) {
    setHandleFromLong(env, instance, handle);
}

JNIEXPORT jlong JNICALL
Java_me_ugo_monujo_models_WalletManager_createWalletHandle(JNIEnv *env, jobject instance,
                                                         jstring path_, jstring password_,
                                                         jstring language_, jboolean inTestNet) {
    const char *path = env->GetStringUTFChars(path_, 0);
    const char *password = env->GetStringUTFChars(password_, 0);
    const char *language = env->GetStringUTFChars(language_, 0);

    Monero::Wallet* wallet = Monero::WalletManagerFactory::getWalletManager()->createWallet(std::string(path),
                                                                                                   std::string(password),
                                                                                                   std::string(language),
                                                                                                   inTestNet);

    env->ReleaseStringUTFChars(path_, path);
    env->ReleaseStringUTFChars(password_, password);
    env->ReleaseStringUTFChars(language_, language);

    jlong handle = reinterpret_cast<jlong>(wallet);
    return handle;
}

JNIEXPORT jlong JNICALL
Java_me_ugo_monujo_models_WalletManager_openWalletHandle(JNIEnv *env, jobject instance,
                                                         jstring path_, jstring password_,
                                                         jboolean inTestNet) {
    const char *path = env->GetStringUTFChars(path_, 0);
    const char *password = env->GetStringUTFChars(password_, 0);

    Monero::Wallet* wallet = Monero::WalletManagerFactory::getWalletManager()->openWallet(std::string(path),
                                                                                                  std::string(password),
                                                                                                  inTestNet);

    env->ReleaseStringUTFChars(path_, path);
    env->ReleaseStringUTFChars(password_, password);

    jlong handle = reinterpret_cast<jlong>(wallet);
    return handle;
}

JNIEXPORT jlong JNICALL
Java_me_ugo_monujo_models_WalletManager_recoveryWalletHandle(JNIEnv *env, jobject instance,
                                                            jstring path_, jstring memo_,
                                                            jlong restoreHeight,
                                                            jboolean inTestNet) {
    const char *path = env->GetStringUTFChars(path_, 0);
    const char *memo = env->GetStringUTFChars(memo_, 0);

    Monero::Wallet* wallet = Monero::WalletManagerFactory::getWalletManager()->recoveryWallet(std::string(path),
                                                                                                    std::string(memo),
                                                                                                    inTestNet);

    env->ReleaseStringUTFChars(path_, path);
    env->ReleaseStringUTFChars(memo_, memo);

    jlong handle = reinterpret_cast<jlong>(wallet);
    return handle;
}

JNIEXPORT jstring JNICALL
Java_me_ugo_monujo_models_Wallet_getAddress(JNIEnv *env, jobject instance) {

    Monero::Wallet* wallet = getHandle<Monero::Wallet>(env, instance);
    const char * address = wallet->address().c_str();

    return env->NewStringUTF(address);
}