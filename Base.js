import firebase from "firebase/app";
import "firebase/auth";

const firebaseConfig = {
  apiKey: "AIzaSyCG53o4DkoU5rsdG_0SBtjd3dxxEJ2m6R0",
  authDomain: "nwitter-5cc06.firebaseapp.com",
  projectId: "nwitter-5cc06",
  storageBucket: "nwitter-5cc06.appspot.com",
  messagingSenderId: "362447675295",
  appId: "1:362447675295:web:34c014b2ae66dd9ca8e7aa"
};

firebase.initializeApp(firebaseConfig);

export const firebaseInstance = firebase;
export const authService = firebase.auth();