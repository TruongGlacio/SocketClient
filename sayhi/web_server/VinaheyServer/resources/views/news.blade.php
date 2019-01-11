@extends('layouts.default')

@section('style')
<style type="text/css">
		.imagePreview {
			width: 100%;
			height: 180px;
			background-position: center center;
			background:url(./images/no-image.gif);
			background-color:#fff;
			background-size: cover;
			background-repeat:no-repeat;
			display: inline-block;
			box-shadow:0px -3px 6px 2px rgba(0,0,0,0.2);
		}
		.upload-btn
		{
			display:block;
			border-radius:0px;
			box-shadow:0px 4px 6px 2px rgba(0,0,0,0.2);
			margin-top:-5px;
		}
		.imgUp
		{
			margin-bottom:15px;
		}
		.del
		{
			position:absolute;
			top:0px;
			right:15px;
			width:30px;
			height:30px;
			text-align:center;
			line-height:30px;
			background-color:rgba(255,255,255,0.6);
			cursor:pointer;
		}
		.imgAdd
		{
			width:30px;
			height:30px;
			border-radius:50%;
			background-color:#4bd7ef;
			color:#fff;
			box-shadow:0px 0px 2px 1px rgba(0,0,0,0.2);
			text-align:center;
			line-height:30px;
			margin-top:0px;
			cursor:pointer;
			font-size:15px;
		}
</style>
@endsection

@section('content')

<div class="col-lg-12 grid-margin stretch-card">
<div class="card">
	<div class="card-body">
		<h4 class="card-title">News</h4>
		<p class="card-description">
			<button type="button" class="btn btn-outline-success" data-toggle="modal" data-target="#exampleModal">
				<i class="mdi mdi-plus"></i>
				<span>Add News</span>
			</button>
			<!-- Modal -->
			<div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
				<div class="modal-dialog modal-lg modal-dialog-centered" role="document">
					<div class="modal-content">
						<div class="modal-header">
							<h5 class="modal-title" id="exampleModalLabel">Adding News</h5>
							<button type="button" class="close" data-dismiss="modal" aria-label="Close">
								<span aria-hidden="true">&times;</span>
							</button>
						</div>
						<div class="modal-body modal-dialog-centered">
							<br>
							<div class="container">
								<div class="row">
									<div class="col-sm-2 imgUp">
										<div class="imagePreview"></div>
										<label class="btn btn-primary upload-btn">
											Upload<input type="file" class="uploadFile img" name="file[]" value="Upload Photo" style="width: 0px;height: 0px;overflow: hidden;">
										</label>
									</div><!-- col-2 -->
									<i class="mdi mdi-plus imgAdd"></i>
								</div><!-- row -->
							</div><!-- container -->
						</div>
						<div class="modal-footer">
							<button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
							<button type="button" class="btn btn-primary" onclick="myFunction()">Save changes</button>
						</div>
					</div>
				</div>
			</div>
		</p>
		<div class="table-responsive" id="mainDiv">
			<table class="table table-striped">
				<thead>
					<tr>
						<th>
							Thumbnail
						</th>
						<th>
							Display Order
						</th>
						<th>
							Created At
						</th>
					</tr>
				</thead>
				<tbody>
					@foreach($news as $new)
						<tr>
							<td class="">
								<img src="{{'/ProtectImage/' . Auth::user()->name . '/' . $new->name}}" alt="image">
							</td>
							<td>
								{{$new->orderID}}
							</td>
							<td>
								{{date('Y-m-d', strtotime($new->created_at))}}
							</td>
						</tr>
					@endforeach
				</tbody>
			</table>
		</div>
	</div>
</div>
</div>

@endsection

@section('javascript')
	<script type="text/javascript">
		$(".imgAdd").click(function(){
			$(this).closest(".row").find('.imgAdd').before('<div class="col-sm-2 imgUp"><div class="imagePreview"></div><label class="btn btn-primary upload-btn">Upload<input type="file" class="uploadFile img" name="file[]" value="Upload Photo" style="width:0px;height:0px;overflow:hidden;"></label><i class="mdi mdi-window-close del"></i></div>');
		});
		$(document).on("click", "i.del" , function() {
			$(this).parent().remove();
		});
		$(function() {
			$(document).on("change",".uploadFile", function()
			{
				var uploadFile = $(this);
				var files = !!this.files ? this.files : [];
				if (!files.length || !window.FileReader) return; // no file selected, or no FileReader support
		
				if (/^image/.test( files[0].type)){ // only image file
					var reader = new FileReader(); // instance of the FileReader
					reader.readAsDataURL(files[0]); // read the local file
		
					reader.onloadend = function(){ // set image data as background of div
						uploadFile.closest(".imgUp").find('.imagePreview').css("background-image", "url("+this.result+")");
					}
				}
			});
		});
	
	function myFunction() {
		var formData = new FormData();
		$('input[type=file]').each(function(i, file) {
			if ($('input[type=file]')[i].files[0] && $('input[type=file]')[i].files[0].type.match('image.*')) {
		    	formData.append('photos[]', $('input[type=file]')[i].files[0]);
			}
		});

		$.ajax({
			type: "POST",
			url: "http://localhost:8000/api/news",
			headers: {
				'Authorization':'Bearer ' + '{{ Auth::user()->api_token }}',
			},
			data: formData, // serializes the form's elements.
			contentType: false,
			processData: false, 
			success: function(data)
			{
				$(".modal:visible").modal('toggle');
				$('#mainDiv').load("http://localhost:8000/news" + ' #mainDiv');
			}
		 });

		e.preventDefault(); // avoid to execute the actual submit of the form.
	}
	</script>
@endsection