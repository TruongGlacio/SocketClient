<!DOCTYPE html>
<html lang="en">
<head>
	<!-- Required meta tags -->
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<title>Vinahey</title>
	<!-- plugins:css -->
	<link rel="stylesheet" href="vendors/iconfonts/mdi/css/materialdesignicons.min.css">
	<link rel="stylesheet" href="vendors/css/vendor.bundle.base.css">
	<link rel="stylesheet" href="vendors/css/vendor.bundle.addons.css">
	<!-- endinject -->
	<!-- plugin css for this page -->
	<!-- End plugin css for this page -->
	<!-- inject:css -->
	<link rel="stylesheet" href="css/style.css">
	<!-- endinject -->
	<link rel="shortcut icon" href="images/favicon.png" />
	@yield('style')
</head>

<body>
	<div class="container-scroller">
		<!-- partial:partials/_navbar.html -->
		<nav class="navbar default-layout col-lg-12 col-12 p-0 fixed-top d-flex flex-row">
			<div class="text-center navbar-brand-wrapper d-flex align-items-top justify-content-center">
				<a class="navbar-brand brand-logo" href="index.html">
					<img src="data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiID8+DQo8IURPQ1RZUEUgc3ZnIFBVQkxJQyAiLS8vVzNDLy9EVEQgU1ZHIDEuMS8vRU4iICJodHRwOi8vd3d3LnczLm9yZy9HcmFwaGljcy9TVkcvMS4xL0RURC9zdmcxMS5kdGQiPg0KPHN2ZyB3aWR0aD0iMTM1cHQiIGhlaWdodD0iMTIycHQiIHZpZXdCb3g9IjAgMCAxMzUgMTIyIiB2ZXJzaW9uPSIxLjEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+DQo8ZyBpZD0iIzJlNTdhMGZmIj4NCjxwYXRoIGZpbGw9IiMyZTU3YTAiIG9wYWNpdHk9IjEuMDAiIGQ9IiBNIDAuNDcgOS4xMCBDIDEuODggNi4yNyAzLjM3IDMuNDkgNC45MiAwLjc0IEMgMzQuMDEgMC45MyA2My4wOCAwLjMwIDkyLjE3IDAuNTEgQyA4NS43NyAxMi4wNyA3OS41MyAyMy43MCA3My4xMyAzNS4yNSBDIDUzLjczIDM1LjI0IDM0LjM0IDM1LjI2IDE0Ljk1IDM1LjI0IEMgMTAuMjEgMjYuNDggNC45NCAxNy45NyAwLjQ3IDkuMTAgWiIgLz4NCjwvZz4NCjxnIGlkPSIjMDU3YmJhZmYiPg0KPHBhdGggZmlsbD0iIzA1N2JiYSIgb3BhY2l0eT0iMS4wMCIgZD0iIE0gNjguMTggNDguMjMgQyA3Ni43MSAzMi4zNSA4NS4wOCAxNi4zNyA5My42MyAwLjUwIEMgMTA0LjUwIDAuNTIgMTE1LjM4IDAuMzggMTI2LjI0IDAuNzUgQyAxMjguMDIgMy45MSAxMjkuNjYgNy4xNSAxMzEuMzMgMTAuMzcgQyAxMTcuNDQgMzYuNDQgMTAzLjcwIDYyLjYwIDg5LjYzIDg4LjU3IEMgODIuNTQgNzUuMDkgNzUuMTIgNjEuNzkgNjguMTggNDguMjMgWiIgLz4NCjwvZz4NCjxnIGlkPSIjMWIzMzY4ZmYiPg0KPHBhdGggZmlsbD0iIzFiMzM2OCIgb3BhY2l0eT0iMS4wMCIgZD0iIE0gNDAuNTIgODIuNjAgQyAzMi40MiA2Ny4zMSAyMy45OCA1Mi4xNyAxNi4xOCAzNi43MyBDIDMwLjc1IDM2Ljc2IDQ1LjMyIDM2Ljc2IDU5Ljg5IDM2Ljc0IEMgNjkuNTIgNTQuNzkgNzkuMTggNzIuODMgODguNzQgOTAuOTIgQyA4My4yNCAxMDEuMjkgNzcuNzYgMTExLjY3IDcyLjE5IDEyMi4wMCBMIDYxLjQ1IDEyMi4wMCBDIDU0LjQ3IDEwOC44NyA0Ny4xNiA5NS45MSA0MC41MiA4Mi42MCBaIiAvPg0KPC9nPg0KPC9zdmc+DQo=" alt="Vue Admin Panel Framework">
				</a>
			</div>
			<div class="navbar-menu-wrapper d-flex align-items-center">
				<ul class="navbar-nav navbar-nav-right">
					<li class="nav-item dropdown d-none d-xl-inline-block">
						<a class="nav-link dropdown-toggle" id="UserDropdown" href="#" data-toggle="dropdown" aria-expanded="false">
							<span class="profile-text">{{ Auth::user()->name }}!</span>
							<img class="img-xs rounded-circle" src="images/faces/face1.jpg" alt="Profile image">
						</a>
						<div class="dropdown-menu dropdown-menu-right navbar-dropdown" aria-labelledby="UserDropdown">
							<a class="dropdown-item"  href="/profile">
                                User Profile
                            </a>
							<a class="dropdown-item" href="{{ route('logout') }}"
                                onclick="event.preventDefault();
                                         document.getElementById('logout-form').submit();">
                                Logout
                            </a>
                            <form id="logout-form" action="{{ route('logout') }}" method="POST" style="display: none;">
                                {{ csrf_field() }}
                            </form>
						</div>
					</li>
				</ul>
				<button class="navbar-toggler navbar-toggler-right d-lg-none align-self-center" type="button" data-toggle="offcanvas">
					<span class="mdi mdi-menu"></span>
				</button>
			</div>
		</nav>
		<!-- partial -->
		<div class="container-fluid page-body-wrapper">
			<!-- partial:partials/_sidebar.html -->
			<nav class="sidebar sidebar-offcanvas" id="sidebar">
				<ul class="nav">
					<li class="nav-item nav-profile">
						<div class="nav-link">
							<div class="user-wrapper">
								<div class="profile-image">
									<img src="images/faces/face1.jpg" alt="profile image">
								</div>
								<div class="text-wrapper">
									<p class="profile-name">{{ Auth::user()->name }}</p>
									<div>
										<small class="designation text-muted">Manager</small>
										<span class="status-indicator online"></span>
									</div>
								</div>
							</div>
						</div>
					</li>
					<li class="nav-item">
						<a class="nav-link" data-toggle="collapse" href="#ui-basic" aria-expanded="true" aria-controls="ui-basic">
							<i class="menu-icon mdi mdi-content-copy"></i>
							<span class="menu-title">Config Menu</span>
							<i class="menu-arrow"></i>
						</a>
						<div class="collapse show" id="ui-basic">
							<ul class="nav flex-column sub-menu">
								<li class="nav-item">
									<a class="nav-link active" href="/">News</a>
								</li>
								<li class="nav-item">
									<a class="nav-link" href="#">Company Structure</a>
								</li>
								<li class="nav-item">
									<a class="nav-link" href="#">For fun</a>
								</li>
								<li class="nav-item">
									<a class="nav-link" href="#">Technology</a>
								</li>
							</ul>
						</div>
					</li>
					<li class="nav-item">
						<a class="nav-link" data-toggle="collapse" href="#standby" aria-expanded="true" aria-controls="standby">
							<i class="menu-icon mdi mdi-content-copy"></i>
							<span class="menu-title">Config StandBy</span>
							<i class="menu-arrow"></i>
						</a>
						<div class="collapse show" id="standby">
							<ul class="nav flex-column sub-menu">
								<li class="nav-item">
									<a class="nav-link" href="pages/ui-features/buttons.html">Hot News</a>
								</li>
								<li class="nav-item">
									<a class="nav-link" href="pages/ui-features/typography.html">Welcome customer</a>
								</li>
							</ul>
						</div>
					</li>
				</ul>
			</nav>
			<!-- partial -->
			<div class="main-panel">
				<div class="content-wrapper">
					@yield('content')
				</div>
				<!-- content-wrapper ends -->
				<!-- partial:partials/_footer.html -->
				<footer class="footer">
					<div class="container-fluid clearfix">
						<span class="text-muted d-block text-center text-sm-left d-sm-inline-block">Copyright © 2018
							<a href="http://www.bootstrapdash.com/" target="_blank">Bootstrapdash</a>. All rights reserved.</span>
						<span class="float-none float-sm-right d-block mt-1 mt-sm-0 text-center">Hand-crafted & made with
							<i class="mdi mdi-heart text-danger"></i>
						</span>
					</div>
				</footer>
				<!-- partial -->
			</div>
			<!-- main-panel ends -->
		</div>
		<!-- page-body-wrapper ends -->
	</div>
	<!-- container-scroller -->

	<!-- plugins:js -->
	<script src="vendors/js/vendor.bundle.base.js"></script>
	<script src="vendors/js/vendor.bundle.addons.js"></script>
	<!-- endinject -->
	<!-- Plugin js for this page-->
	<!-- End plugin js for this page-->
	<!-- inject:js -->
	<script src="js/off-canvas.js"></script>
	<script src="js/misc.js"></script>
	<!-- endinject -->
	<!-- Custom js for this page-->
	<script src="js/dashboard.js"></script>
	<!-- End custom js for this page-->
	@yield('javascript')
</body>

</html>