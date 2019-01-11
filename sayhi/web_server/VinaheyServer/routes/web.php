<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Auth::routes();

Route::get('/', 'NewsController@index')->name('home');

Auth::routes();

Route::get('news', 'NewsController@index')->name('news');

Auth::routes();

Route::middleware('auth:web')->get('ProtectImage/{username}/{name}', 'SecuredImageController@show');