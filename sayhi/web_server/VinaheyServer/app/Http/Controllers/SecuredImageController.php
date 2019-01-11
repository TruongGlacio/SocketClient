<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Image;
use Auth;

class SecuredImageController extends Controller {

    public function show($username,$name)
    {
    	error_log("DMMMM");
    	if(Auth::check())
    	{
			$imagePath = storage_path('/images/user_upload/' . $username . '/' . $name);
			error_log($imagePath);
	    	return Image::make($imagePath)->response();
    	}
    }
}