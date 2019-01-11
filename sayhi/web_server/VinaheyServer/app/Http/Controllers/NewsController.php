<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Validator;
use Auth;
use App\News;
class NewsController extends Controller
{
	/**
	 * Create a new controller instance.
	 *
	 * @return void
	 */
	public function __construct()
	{
		$this->middleware('auth');
	}

	/**
	 * Show the application dashboard.
	 *
	 * @return \Illuminate\Http\Response
	 */
	public function index()
	{
		return view('news', ['news' => News::all()]);
	}

	public function create(Request $request)
	{
		error_log($request);

		$validator = Validator::make($request->all(), [
			'photos' => 'required',
			'photos.*' => 'image|mimes:jpeg,png,jpg,gif,svg|max:2048'
		]);

		if ($validator->fails()) {
			return response()->json([
				'msg' => 'Missing image'
			], 400);
		} else
		{
			if($request->hasfile('photos'))
			{
				News::truncate();
				$count = 1;
				foreach($request->file('photos') as $image)
				{
					$name=$image->getClientOriginalName();
					$filename = pathinfo($name, PATHINFO_FILENAME);
					$extension = pathinfo($name, PATHINFO_EXTENSION);
					$unix_timestamp = now()->timestamp;
					$image->move(storage_path().'/images/user_upload/' . Auth::user()->name . '/', $filename . '_' . $unix_timestamp . '.' . $extension); 
					
					$insertNews = new News;
					$insertNews->name = $filename . '_' . $unix_timestamp . '.' . $extension;
					$insertNews->orderID = $count;
					$insertNews->save();
					
					$count++;
				}
			}
			return response()->json([
				'msg' => 'Success'
			]);
		}
	}

	public function get()
	{
		$news = News::all();
		return response()->json([
			'id' => 1,
			'data' => $news,
			'createDate' => date("Ymd", time())
		]);
	}

}
