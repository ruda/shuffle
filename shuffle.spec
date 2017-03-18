Summary: Print a random permutation of the argument list
Name: shuffle
Version: 1.17.3
Release: 1%{?dist}
Group: Applications/System
License: BSD
URL: https://github.com/ruda/shuffle/archive/
Source: %{version}.tar.gz

%description
Shuffle prints to standard output a random permutation of the argument list.

Knuth algorithm (in fact Fisher-Yates shuffle) is used to garante
truly random permutations.

%prep
%setup -q

%build
make %{_smp_mflags} PREFIX=%{_prefix}

%install
make DESTDIR=%{buildroot} PREFIX=%{_prefix} install

%check
./test.sh

%files
%doc README LICENSE
%defattr(-,root,root,-)
%{_bindir}/shuffle
%{_mandir}/man1/shuffle.1*

%changelog
