package org.apache.cordova.estat;

import fr.mediametrie.mesure.library.android.*;
import com.squareup.tape.*;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import android.R;
import android.content.Context;
import android.content.DialogInterface;
import android.app.AlertDialog;
 
public class estat extends CordovaPlugin {
 
  public Boolean trackerStarted = false;
  
  public String serial = "";
  
  public EstatAudienceTagger audienceTagger = null;
  
  public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
    if("initEstat".equals(action)){
      String id = args.getString(0);
	  if(!trackerStarted) { this.startTracker(id, callbackContext); }
      callbackContext.success();
      return true;
    }else if("sendHitEstat".equals(action)){
		this.sendHit(args.getJSONArray(0), callbackContext);
		callbackContext.success();
      return true;
    } else {
      callbackContext.error("AlertPlugin."+action+" not found !");
      return false;
    }
  }
 
  private void showAlert(String content){
    // see http://developer.android.com/guide/topics/ui/dialogs.html
    AlertDialog.Builder alertDialog = new AlertDialog.Builder(this.cordova.getActivity(), AlertDialog.THEME_DEVICE_DEFAULT_LIGHT);
    alertDialog.setTitle("Alert");
    alertDialog.setMessage(content);
    alertDialog.setPositiveButton(R.string.ok, new DialogInterface.OnClickListener(){
      public void onClick(DialogInterface dialog, int id){
        // User clicked OK button
      }
    });
    alertDialog.show();
  }
  
   private void startTracker(String id, CallbackContext callbackContext) {
        if (null != id && id.length() > 0) {
            //GoogleAnalytics.getInstance(this.cordova.getActivity()).getTracker(id);
			Estat.init(this.cordova.getActivity());
			Estat.setLog(BuildConfig.DEBUG);
			serial = id;
			audienceTagger = Estat.getAudience(serial, "");
			trackerStarted = true;
            callbackContext.success("estat started");
			AlertDialog.Builder alertDialog = new AlertDialog.Builder(this.cordova.getActivity(), AlertDialog.THEME_DEVICE_DEFAULT_LIGHT);
			alertDialog.setTitle("eStat started !");
			alertDialog.setMessage(id + " V." + Estat.getVersion());
			alertDialog.setPositiveButton(R.string.ok, new DialogInterface.OnClickListener(){
			  public void onClick(DialogInterface dialog, int id){
				// User clicked OK button
			  }
			});
			alertDialog.show();
            
            //GAServiceManager.getInstance().setLocalDispatchPeriod(30); //deprecated but whatcha gonna do? set dispatch period to 30 sec
        } else {
            callbackContext.error("serial is not valid");
        }
    }
	
	private void sendHit(JSONArray levels, CallbackContext callbackContext) {
        if (trackerStarted) {
			if(files.length() == 1) {
				audienceTagger.sendHit(levels.getString(0));
				callbackContext.success("estat hit sent");
			} else if(files.length() == 2) {
				audienceTagger.sendHit(levels.getString(0),levels.getString(1));
				callbackContext.success("estat hit sent");
			} else if(files.length() == 3) {
				audienceTagger.sendHit(levels.getString(0),levels.getString(1),levels.getString(2));
				callbackContext.success("estat hit sent");
			} else if(files.length() == 4) {
				audienceTagger.sendHit(levels.getString(0),levels.getString(1),levels.getString(2),levels.getString(3));
				callbackContext.success("estat hit sent");
			} else {
				callbackContext.error("eStat : Levels length not supported");
			}
        } else {
            callbackContext.error("eStat not initialized");
        }
    }
}