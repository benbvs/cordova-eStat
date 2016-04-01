//
//  estat.js
//
// estat Cordova Plugin by Benjamin BEAUVAIS on 31/03/16.
//
// estat Plugin for Cordova Android
// www.lanewscompany.com
//
// MIT Licensed


function estat(){}

// Call this to register for push notifications and retreive a push Token
estat.initEstat = function(serial,success, fail) {
	cordova.exec(success, fail, "estat", "initEstat", [serial]);
};

estat.sendHitEstat = function(levels,success, fail) {
	cordova.exec(success, fail, "estat", "sendHitEstat", [levels]);
};

// Event spawned when a notification is received while the application is active
estat.notificationCallback = function(notification) {
	var ev = document.createEvent('HTMLEvents');
	ev.notification = notification;
	ev.initEvent('push-notification', true, true, arguments);
	document.dispatchEvent(ev);
};

module.exports = estat;
